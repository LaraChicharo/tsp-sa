const int MAX_VERTICES = 1500;

// Constants for tweaking the behaviour of the heuristic
const double TEMPERATURE_DECAY = .95;
const double EPSILON = 1e-4;
const double P = .80; 
const double INITIAL_TEMPERATURE = 1000;
const int L = 1000;
const int PERIOD = 2003;
const int STOP = L * 31;
