#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.SeqEvent_MobileSwipe." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.SeqEvent_MobileSwipe." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.SeqEvent_MobileSwipe." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqEvent_MobileSwipe : public SeqEvent_MobileRawInput
	{
	public:
			ADD_VAR( ::FloatProperty, MinDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Tolerance, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
