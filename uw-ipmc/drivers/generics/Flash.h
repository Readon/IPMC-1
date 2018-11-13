/*
 * Flash.h
 *
 *  Created on: Aug 27, 2018
 *      Author: mpv
 */

#ifndef SRC_COMMON_UW_IPMC_DRIVERS_GENERICS_FLASH_H_
#define SRC_COMMON_UW_IPMC_DRIVERS_GENERICS_FLASH_H_

#include <stdint.h>
#include <string>

/**
 * Abstract flash interface.
 * Before any operation takes place the flash needs to be initialized
 * by calling isInitialized when appropriate and internally this will
 * detect the flash type and size.
 * Only then read/write operations are allowed and only JEDEC compatible
 * flashes are supported.
 */
class Flash {
public:
	Flash() : initialized(false), parameters({0}) {};

	///! true if the flash has already been initialized, false otherwise.
	inline bool isInitialized() { return this->initialized; };

	/**
	 * Initialize the flash by checking the JEDEC registers.
	 * Multiple calls will only trigger a single initialization.
	 * @return true if initialization successful (JEDEC compatible flash detected), false otherwise.
	 */
	bool initialize() {
		if (this->isInitialized()) return true;

		if (this->getJEDECInfo()) {
			this->initialized = true;
			return true;
		} else
			return false;
	};

	/**
	 * Read a set of bytes to a provided pre-allocated buffer.
	 * @param address Start address in the flash.
	 * @param buffer Pre-allocated buffer to store read data.
	 * @param bytes Number of bytes to read from flash.
	 * @return true if read was successful, false otherwise.
	 * @warning The sum of address and bytes cannot exceed flash total size, this will cause read to fail.
	 */
	virtual bool read(uint32_t address, uint8_t *buffer, size_t bytes) = 0;

	/**
	 * Write a set of bytes to the flash.
	 * @param address Start address in the flash.
	 * @param buffer Buffer with data to be written to flash.
	 * @param bytes Number of bytes to write to flash.
	 * @return true if write was successful, false otherwise.
	 * @warning The sum of address and bytes cannot exceed flash total size, this will cause write to fail.
	 */
	virtual bool write(uint32_t address, const uint8_t *buffer, size_t bytes) = 0;

	///! Returns the flash size in bytes or zero if flash wasn't been initialized or is incompatible.
	inline size_t getTotalSize() {
		if (this->parameters.memoryDensityExp) return (1 << (this->parameters.memoryDensity >> 3));
		else return ((this->parameters.memoryDensity+1) >> 3);
	}

	///! Returns the flash sector size in bytes or zero if flash wasn't been initialized yet.
	inline size_t getSectorSize(uint8_t sector = 0) {
		if ((sector > 4) || (this->parameters.sectors[sector].size == 0)) return 0;

		return (1 << (this->parameters.sectors[sector].size));
	}

protected:
	/**
	 * Fill the JEDEC parameters structure from flash.
	 * @return false if flash is not JEDEC compliant of if there is a communication issue, true otherwise.
	 */
	virtual bool getJEDECInfo() = 0;

	///! Disables write protections.
	virtual bool disableWriteProtections() = 0;

	///! Enables writing to the flash. Automatically de-asserted after a write operation.
	virtual bool enableWriting() = 0;

	///! Disable writing to the flash.
	virtual bool disableWriting() = 0;

	///! Wait for a write operation to complete.
	virtual bool waitForWriteComplete() = 0;

	/**
	 * Write a single page to the flash.
	 * @param address Page address.
	 * @param buffer Buffer with data to write with exactly 256 bytes.
	 * @param bytes Number of bytes to write, must be 256.
	 * @return false if arguments are invalid or if write failed, true otherwise.
	 */
	virtual bool writePage(uint32_t address, const uint8_t *buffer, size_t bytes) = 0;

	/**
	 * Erase a group of sectors, from address to (address + bytes).
	 * @param address First sector address, must be aligned to the sector size.
	 * @param bytes Number of bytes to erase.
	 * @return true if success, false otherwise.
	 * @warning If address is not aligned nor the total number of bytes is a multiple
	 * of the sector size then the operation will fail.
	 */
	virtual bool eraseSectors(uint32_t address, size_t bytes) = 0;

	struct SFDP_First_Header {
		uint32_t signature : 32;
		uint8_t minor_revision : 8;
		uint8_t major_revision : 8;
		uint8_t num_headers : 8;
		uint8_t : 8;
	};

	struct SFDP_Table_Entry {
		uint8_t id_number : 8;
		uint8_t minor_revision : 8;
		uint8_t major_revision : 8;
		uint8_t length_words : 8;
		uint32_t pointer : 24;
		uint8_t : 8;
	};

	struct JEDECFlashParameters {
		// Word 1
		uint32_t blockSectorEraseSize : 2;
		uint32_t writeGranularity : 1;
		uint32_t writeEnableRequiredToWriteToStatusRegister : 1;
		uint32_t writeEnableOpcodeSelectToWriteToStatusRegister : 1;
		uint32_t : 3;
		uint32_t eraseOpcode : 8;
		uint32_t supports112FastRead : 1;
		uint32_t addressBytes : 2;
		uint32_t supportsDoubleTransferRate : 1;
		uint32_t supports122FastRead : 1;
		uint32_t supports144FastRead : 1;
		uint32_t supports114FastRead : 1;
		uint32_t : 9;
		// Word 2
		uint32_t memoryDensity : 31;
		uint32_t memoryDensityExp : 1;
		// Word 3
		uint32_t fastRead144NumberOfWaits : 5;
		uint32_t fastRead144NumberOfModeBits : 3;
		uint32_t fastRead144OpCode : 8;
		uint32_t fastRead114NumberOfWaits : 5;
		uint32_t fastRead114NumberOfModeBits : 3;
		uint32_t fastRead114OpCode : 8;
		// Word 4
		uint32_t fastRead112NumberOfWaits : 5;
		uint32_t fastRead112NumberOfModeBits : 3;
		uint32_t fastRead112OpCode : 8;
		uint32_t fastRead122NumberOfWaits : 5;
		uint32_t fastRead122NumberOfModeBits : 3;
		uint32_t fastRead122OpCode : 8;
		// Word 5
		uint32_t supports222FastRead : 1;
		uint32_t : 3;
		uint32_t supports444FastRead : 1;
		uint32_t : 27;
		// Word 6
		uint32_t : 16;
		uint32_t fastRead222NumberOfWaits : 5;
		uint32_t fastRead222NumberOfModeBits : 3;
		uint32_t fastRead222OpCode : 8;
		// Word 7
		uint32_t : 16;
		uint32_t fastRead444NumberOfWaits : 5;
		uint32_t fastRead444NumberOfModeBits : 3;
		uint32_t fastRead444OpCode : 8;
		// Word 8 & 9
		struct Sector {uint8_t size; uint8_t opcode;} sectors[4];
	};

	struct StatusRegister {
		union {
			struct {
				uint8_t writeInProgress : 1;
				uint8_t writeEnableLatch : 1;
				uint8_t blockProtect0 : 1;
				uint8_t blockProtect1 : 1;
				uint8_t : 4;
			};
			uint8_t _raw;
		};
	};

	///! Get the status register from the flash.
	virtual StatusRegister getStatusRegister() = 0;

	bool initialized;					///< Indicates if initialized and if parameters is valid.
	JEDECFlashParameters parameters;	///< JEDEC parameters of the flash.
};



#endif /* SRC_COMMON_UW_IPMC_DRIVERS_GENERICS_FLASH_H_ */