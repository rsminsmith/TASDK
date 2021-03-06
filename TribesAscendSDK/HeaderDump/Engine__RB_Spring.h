#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.RB_Spring." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.RB_Spring." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.RB_Spring." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RB_Spring : public ActorComponent
	{
	public:
			ADD_VAR( ::FloatProperty, DampMaxForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DampSaturateVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxForceMassRatio, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpringMaxForce, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SpringSaturateDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinBodyMass, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeSinceActivation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableForceMassRatio, 0x2 )
			ADD_VAR( ::BoolProperty, bInHardware, 0x1 )
			ADD_VAR( ::IntProperty, SceneIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName2, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BoneName1, 0xFFFFFFFF )
			void SetComponents( ScriptName InBoneName1, Vector Position1, ScriptName InBoneName2, Vector Position2 )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_Spring.SetComponents" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( ScriptName* )( params + 4 ) = InBoneName1;
				*( Vector* )( params + 12 ) = Position1;
				*( ScriptName* )( params + 28 ) = InBoneName2;
				*( Vector* )( params + 36 ) = Position2;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Clear(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.RB_Spring.Clear" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
