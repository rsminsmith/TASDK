#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.AnimNodeAimOffset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.AnimNodeAimOffset." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.AnimNodeAimOffset." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class AnimNodeAimOffset : public AnimNodeBlendBase
	{
	public:
			ADD_VAR( ::IntProperty, CurrentProfileIndex, 0xFFFFFFFF )
			ADD_OBJECT( AnimNodeAimOffset, TemplateNode )
			ADD_VAR( ::ByteProperty, ForcedAimDir, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PassThroughAtOrAboveLOD, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSynchronizeNodesInEditor, 0x8 )
			ADD_VAR( ::BoolProperty, bPassThroughWhenNotRendered, 0x4 )
			ADD_VAR( ::BoolProperty, bBakeFromAnimations, 0x2 )
			ADD_VAR( ::BoolProperty, bForceAimDir, 0x1 )
			void SetActiveProfileByName( ScriptName ProfileName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeAimOffset.SetActiveProfileByName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = ProfileName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetActiveProfileByIndex( int ProfileIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.AnimNodeAimOffset.SetActiveProfileByIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = ProfileIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
