/// @brief Document containing constats for the program and for
/// the heuristic itself.
#pragma once

/// Maximum number of vertices the program is going to handle
const int MAX_VERTICES = 1500;

// Constants for tweaking the behaviour of the heuristic

/// Rate in with temperature is going to decrease
const double TEMPERATURE_DECAY = .95;
/// Virtual zero
const double EPSILON = 1e-4;
/// Percentage of 
const double P = .80;
/// Initial temperature
const double INITIAL_TEMPERATURE = 1000;
/// Size of the batch
const int L = 2000;
/// The heuristic is going to calculate the cost of a solution every PERIOD times in linear time (as opposed to constant as is normally done)
/// to avoid accumulating decimal error
const int PERIOD = 4003;
/// Stop a batch after this many iterations it batch is still running
const int STOP = L * 31;
