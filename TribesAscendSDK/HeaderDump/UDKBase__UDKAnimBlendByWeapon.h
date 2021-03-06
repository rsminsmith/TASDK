#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKAnimBlendByWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKAnimBlendByWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKAnimBlendByWeapon." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKAnimBlendByWeapon : public AnimNodeBlendPerBone
	{
	public:
			ADD_VAR( ::FloatProperty, BlendTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, LoopingAnim, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLooping, 0x1 )
			void AnimFire( ScriptName FireSequence, bool bAutoFire, float AnimRate, float SpecialBlendTime, ScriptName LoopSequence )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKAnimBlendByWeapon.AnimFire" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( ScriptName* )( params + 0 ) = FireSequence;
				*( bool* )( params + 8 ) = bAutoFire;
				*( float* )( params + 12 ) = AnimRate;
				*( float* )( params + 16 ) = SpecialBlendTime;
				*( ScriptName* )( params + 20 ) = LoopSequence;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AnimStopFire( float SpecialBlendTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKAnimBlendByWeapon.AnimStopFire" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = SpecialBlendTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
