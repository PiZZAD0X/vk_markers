// #define DEBUG_MODE_FULL
#include "script_component.hpp"
// PARAMS_3(_vehicle,_pos,_unit);
params ["","","_unit"];

if (_unit == player) then {
	GVAR(playerBFT) = false;
	// LOG("BFT Off");
};