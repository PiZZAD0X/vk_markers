// #define DEBUG_MODE_FULL
#include "script_component.hpp"

params ["_unit"];
TRACE_1("Params",_unit);

private ["_markerData","_markerArray","_killedType","_pos","_dummy"];

_markerData = _unit getVariable QGVAR(markerData);
_markerArray = _unit getVariable QGVAR(markerArray);
_killedType = _unit getVariable QGVAR(killedType);

if (isNil "_markerData") exitWith {
	TRACE_1("No markerData for unit",_unit);
	if (!isNil "_markerArray") exitWith {
		_unit setVariable [QGVAR(markerArray),nil,true];
	};
};
if (isNil "_markerArray") exitWith {
	TRACE_1("No markerArray for unit",_unit);
	_unit setVariable [QGVAR(markerData),nil,true];
};

_markerData params ["_name", "_mods", "_type", "_size", "_scale", "_visibleTo", "_text"];
_pos = getPos _unit;

if (isNil "_killedType") then {
	_killedType = GVAR(gKilledType);
};
TRACE_1("",_killedType);
switch (_killedType) do {
	case "static": {
		LOG("Recreate marker as static");
		_unit call FUNC(deleteMarker);
		[_name,_pos,_type,_mods,_size,_scale,_visibleTo,_text] call FUNC(addMarker);
	};
	case "destroy": {
		LOG("Adding destroyed marker");
		// _unit call FUNC(deleteMarker);
		_unit setVariable [QGVAR(markerData),nil,true];
		_unit setVariable [QGVAR(markerArray),nil,true];
		
		CREATEHELPER(_unit,_pos);
		TRACE_2("New Helper",_unit,_pos);
		_markerArray pushback "destroyed";
		// _mods pushback "destroyed";
		_markerData set [1, _mods];
		_markerData set [7, _unit];
		TRACE_1("",_markerData);
		_unit setVariable [QGVAR(markerData),_markerData,true];
		_unit setVariable [QGVAR(markerArray),_markerArray,true];
		
		[_name,_pos,_type,_mods,_size,_scale,_visibleTo,_text] call FUNC(addMarker);
	};
	case "remove": {
		LOG("Remove marker");
		_unit call FUNC(deleteMarker);
	};
};