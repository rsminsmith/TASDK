#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SeqAct_AccessObjectList." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SeqAct_AccessObjectList." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SeqAct_AccessObjectList." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SeqAct_AccessObjectList : public SeqAct_SetSequenceVariable
	{
	public:
			ADD_VAR( ::IntProperty, ObjectIndex, 0xFFFFFFFF )
			ADD_OBJECT( Object, OutputObject )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
