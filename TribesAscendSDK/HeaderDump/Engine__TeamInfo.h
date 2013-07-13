#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.TeamInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.TeamInfo." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.TeamInfo." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TeamInfo : public ReplicationInfo
	{
	public:
			ADD_VAR( ::IntProperty, TeamIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Score, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Size, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TeamName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
