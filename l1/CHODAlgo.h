/*
 * CHODAlgo.h
 *
 *  Created on: May 11, 2015
 *      Author: angela romano
 *      Email: axr@hep.ph.bham.ac.uk
 */

#pragma once
#ifndef CHODALGORITHM_H_
#define CHODALGORITHM_H_

#include <sys/types.h>
#include <cstdint>

#include "../common/decoding/DecoderHandler.h"
#include "chod_algorithm/ParsConfFile.h"
#include "L1InfoToStorage.h"
#include "../struct/HLTConfParams.h"
#include "L1Fragment.h"

#define maxNhits 500

namespace na62 {

class CHODAlgo {
public:
	/**
	 * @param event Event* This is a pointer to the built Event containing all subevents (except those from the LKr)
	 *
	 * The event pointer may not be deleted by this method as it is deleted by the EventBuilder
	 *
	 * @return uint_fast8_t <0> if the event is rejected, the L1 trigger type word in other cases.
	 */

	static uint_fast8_t processCHODTrigger(uint l0MaskID,
			DecoderHandler& decoder, L1InfoToStorage* l1Info);
	static void initialize(uint i, l1CHOD &l1ChodStruct);
	static void writeData(L1Algo* algoPacket, uint l0MaskID, L1InfoToStorage* l1Info);

private:

	static CHODParsConfFile* InfoCHOD_;
	static uint AlgoID_; //0 for CHOD, 1 for RICH, 2 for KTAG, 3 for LAV, 4 for IRCSAC, 5 for Straw, 6 for MUV3, 7 for NewCHOD
	static uint AlgoLogic_[16];
	static uint AlgoRefTimeSourceID_[16];
	static double AlgoOnlineTimeWindow_[16];

	static int* SlabGeo_;

};

} /* namespace na62 */
#endif /* CHODALGORITHM_H_ */
