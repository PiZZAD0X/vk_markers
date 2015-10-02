// #define DEBUG_MODE_FULL
#include "script_component.hpp"


if (isDedicated) then {
	LOG("Server: Creating variables");
	ISNILS(GVAR(gKilledType),"remove");
	publicVariable QGVAR(gKilledType);
	GVAR(postInit) = true;
} else {
	TRACE_1("Client: Initializing variables",GVAR(gKilledType));
	
	if (isNil QGVAR(gKilledType)) then {
		GVAR(gKilledType) = "remove";
		publicVariable QGVAR(gKilledType);
	};
	GVAR(postInit) = false;
};


// ----- Private functions -----

PREP(addMarker);
PREP(createMarker);
PREP(killed);
PREP(markerLoop);

FUNC(playerCheck) = {
	LOG("Looking for player");
	if (!isNull player) then {
		TRACE_1("Player found",player);
		[(_this select 1)] call CBA_fnc_removePerFrameHandler;
	};
};

FUNC(hideMarker) = {
	params ["_unit"];
	TRACE_1("HideMarker Params",_unit);
	private ["_markerData"];
	_markerData = _unit getVariable [QGVAR(markerData),[]];
	[QGVAR(deleteMarker),[_markerData select 0, _markerData select 1]] call CBA_fnc_GlobalEvent;
	_unit setVariable [QGVAR(markerArray),nil,false];
	TRACE_2("Deleting marker from unit",_unit,_markerData select 0);
};


// ----- Public functions -----

vk_fnc_addMarker = FUNC(addMarker);

[QGVAR(deleteMarker), {_this call COMPILE_FILE(fnc_deleteMarker)}] call CBA_fnc_addEventHandler;
FUNC(deleteMarker) = {
	params ["_unit"];
	TRACE_1("DeleteMarker Params",_unit);
	private ["_markerData","_markerName"];
	if (IS_STRING(_unit)) then {
		{
			_markerData = _x getVariable [QGVAR(markerData),[]];
			_markerName = _markerData select 0;
			TRACE_1("",_markerData);
			if (_unit == _markerName) then {
				[QGVAR(deleteMarker), _markerData] call CBA_fnc_GlobalEvent;
				_x setVariable [QGVAR(markerData),nil,true];
				_x setVariable [QGVAR(markerArray),nil,true];
				TRACE_2("Deleting marker from unit",_unit,_x);
				if (typeOf _x == "vk_helper_vehicle") then {
					deleteVehicle _x;
				};
			};
		} forEach allUnits + vehicles;
	} else {
		_markerData = _unit getVariable [QGVAR(markerData),[]];
		[QGVAR(deleteMarker), _markerData] call CBA_fnc_GlobalEvent;
		_unit setVariable [QGVAR(markerData),nil,true];
		_unit setVariable [QGVAR(markerArray),nil,true];
		TRACE_2("Deleting marker from unit",_unit,_markerData select 0);
	};
};
vk_fnc_deleteMarker = FUNC(deleteMarker);

FUNC(setBFT) = {
	params ["_unit",["_newState",nil,[true,nil]]];
	TRACE_2("SetBFT Params",_unit,_newState);
	if (isNil "_newState") then {
		_state = _unit getVariable [QGVAR(BFT),false];
		_newState = !_state;
	};
	_unit setVariable [QGVAR(BFT),_newState,true];
	TRACE_1("fnc_setBFT",_newState);
	_newState
};
vk_fnc_setBFT = FUNC(setBFT);
