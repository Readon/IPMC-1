/*
 * atheros.c
 *
 *  Created on: Aug 31, 2017
 *      Author: mpvl
 */

#include "../../uw-ipmc/atheros/atheros.h"

int ar8035_enable_internal_delays(struct netif *netif)
{
	struct xemac_s *xemacp;
	xemacpsif_s *xemacps;
	XEmacPs *xemacpsp;
	u16 regval;

	xemacp = (struct xemac_s*)netif->state;
	xemacps = (xemacpsif_s*)xemacp->state;
	xemacpsp = &xemacps->emacps;

	XEmacPs_PhyWrite(xemacpsp, 4, 0x1d, 0x05);
	XEmacPs_PhyRead(xemacpsp, 4, 0x1e, &regval);

	XEmacPs_PhyWrite(xemacpsp, 4, 0x1d, 0x05);
	XEmacPs_PhyWrite(xemacpsp, 4, 0x1e, (regval|0x0100));

	return 1;
}
