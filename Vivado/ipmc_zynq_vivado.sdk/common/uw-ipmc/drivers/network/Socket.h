/*
 * Socket.h
 *
 *  Created on: Feb 7, 2018
 *      Author: mpv
 */

#ifndef SRC_COMMON_UW_IPMC_DRIVERS_NETWORK_SOCKET_H_
#define SRC_COMMON_UW_IPMC_DRIVERS_NETWORK_SOCKET_H_

#include <lwip/sockets.h>
#include <string>

#include "SocketAddress.h"

/**
 * C++ socket wrapper and automatic cleanup
 *
 * TODO
 */
class Socket {
public:
	/**
	 * Creates a socket instance based upon an already existing
	 * socket file descriptor and sockaddr_in structure.
	 * Used for example after a call to ServerSocket::accept()
	 * @param socket socket file descriptor
	 * @param sockaddr address structure
	 */
	Socket(int socket, struct sockaddr_in sockaddr);

	/**
	 * Creates a new socket based on an address, port and TCP or UDP
	 * @param address The target address.
	 * @param port The port to use.
	 * @param useTCP true if TCP/IP, false if UDP/IP.
	 */
	Socket(std::string address, unsigned short port, bool useTCP = true);

	virtual ~Socket();

	/**
	 * Reads data if present
	 * @param ptr the data buffer
	 * @param len the length of the buffer in buffer
	 * @return The total number of read bytes
	 */
	int read(void *ptr, int len);

	/**
	 * Will read the number of requested bytes
	 * @param ptr the data buffer
	 * @param len number of bytes available in buffer and
	 *            quantity to read
	 * @return 1 if read successful
	 */
	int readn(void *ptr, int len);

	/**
	 * Sends a string to the client
	 * @param str the string to send
	 */
	int send(std::string str);

	/**
	 * Sends an array of charactes to the client
	 * @param buf the character buffer
	 * @param len the starting position
	 * @param flags TODO
	 */
	int send(const void* buf, int len, int flags=0);

	/**
	 * Sets the socket in blocking mode
	 */
	void setBlocking();

	/**
	 * Sets the socket in non-blocking mode
	 */
	void setUnblocking();

	/**
	 * Sets the socket to have no delay on TCP reads
	 */
	void setTCPNoDelay();

	/**
	 * Closes the socket connection
	 */
	void close();

	/**
	 * Checks whether the socket is valid
	 * @return true of the socket is valid, false otherwise
	 */
	inline bool isValid() { return socketfd != -1; }

	/**
	 * Checks if the socket is configured for TCP/IP operation,
	 * if false it means it is UDP
	 * @return true if TCP/IP socket, UDP/IP otherwise
	 */
	bool isTCP();

	/**
	 * Gets the socket file descriptor
	 * @return the socket file descriptor
	 */
	inline int getSocket() { return socketfd; }

	/**
	 * Gets the socketaddress instance of the socket, which contains
	 * information about the socket's address and port
	 * @return the socketaddress instance
	 */
	inline SocketAddress* getSocketAddress() { return sockaddr; }

	///! Operator overload for int assignment, returns socketfd
	inline operator int() { return this->getSocket(); }

protected:
	int socketfd;				///< The socket file descriptor number.
	SocketAddress* sockaddr;	///< The socket address and port.
};

#endif /* SRC_COMMON_UW_IPMC_DRIVERS_NETWORK_SOCKET_H_ */