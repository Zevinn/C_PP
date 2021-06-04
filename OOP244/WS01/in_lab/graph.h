#pragma once
/**********************************************************
 * Name: Min Woo Kim
 * Student ID: kim3
 * Seneca email: kim3@myseneca.ca
 * Section: SEE
 **********************************************************/
#ifndef SICT_GRAPH_H
#define SICT_GRAPH_H
#include "Tools.h"
namespace sict {

#define MAX_NO_OF_SAMPLES 20

	void getSamples(int samples[], int noOfSamples);

	int findMax(int samples[], int noOfSamples);

	void printBar(int val, int max);

	void printGraph(int samples[], int noOfSamples);
}
#endif