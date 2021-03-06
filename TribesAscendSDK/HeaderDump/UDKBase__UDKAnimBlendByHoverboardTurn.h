#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKAnimBlendByHoverboardTurn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKAnimBlendByHoverboardTurn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKAnimBlendByHoverboardTurn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimBlendByHoverboardTurn : public AnimNodeBlendBase
	{
	public:
			ADD_VAR( ::FloatProperty, CurrentAnimWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxBlendPerSec, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TurnScale, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
