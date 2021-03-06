#include "TASDK.h"
#include <deque>

void ScriptObject::LogAll()
{
	OutputLog( "ScriptObject.LogAll output: \n" );
	for( int i = 0; i < object_array()->count(); i++ )
	{
		ScriptObject *object = ( *object_array() )( i );
		if( object )
		{
			OutputLog( "%s\n", object->GetFullName() );
		}
	}
}

bool ScriptObject::IsA( ScriptClass *script_class )
{
	for( ScriptClass *super_class = object_class(); super_class; super_class = ( ScriptClass* )( super_class->super() ) )
	{
		if( super_class == script_class )
		{
			return true;
		}
	}

	return false;
}

struct FuncArg
{
	FuncArg( std::string name_, std::string type_, int offset_, bool out_param_ )
	{
		name = name_;
		type = type_;
		offset = offset_;
		out_param = out_param_;
	}

	std::string name;
	std::string type;
	int offset;
	bool out_param;
};

void ScriptObject::GenerateHeader()
{
	ScriptClass *class_scriptclass = ( ScriptClass* )( this );

	std::string file_name = this->GetName();
	file_name.append( ".h" );

	for( ScriptObject *outer = this->outer(); outer; outer = outer->outer() )
	{
		file_name.insert( 0, "__" );
		file_name.insert( 0, outer->GetName() );
	}

	OutputLogTo( "..\\..\\..\\src\\TribesAscendSDK\\HeaderDump\\HeaderDump.h", "#include \"%s\"\n", file_name.c_str() );

	file_name.insert( 0, "..\\..\\..\\src\\TribesAscendSDK\\HeaderDump\\" );
	InitLoggingTo( file_name.c_str() );

	OutputLogTo( file_name.c_str(), "#pragma once\n" );

	OutputLogTo( file_name.c_str(), "#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \\\n" );
	OutputLogTo( file_name.c_str(), "{ \\\n" );
	OutputLogTo( file_name.c_str(), "\tstatic ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x \" %s.%s.\" #y ); \\\n", this->outer()->GetName(), this->GetName() );
	OutputLogTo( file_name.c_str(), "\treturn ( ##x( this, script_property->offset, z ) ); \\\n" );
	OutputLogTo( file_name.c_str(), "}\n" );

	OutputLogTo( file_name.c_str(), "#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \\\n" );
	OutputLogTo( file_name.c_str(), "{ \\\n" );
	OutputLogTo( file_name.c_str(), "\tstatic ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( \"StructProperty %s.%s.\" #y ); \\\n", this->outer()->GetName(), this->GetName() );
	OutputLogTo( file_name.c_str(), "\treturn ( ##x( this, script_property->offset, z ) ); \\\n" );
	OutputLogTo( file_name.c_str(), "}\n" );

	OutputLogTo( file_name.c_str(), "#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \\\n" );
	OutputLogTo( file_name.c_str(), "{ \\\n" );
	OutputLogTo( file_name.c_str(), "\tstatic ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( \"ObjectProperty %s.%s.\" #y ); \\\n", this->outer()->GetName(), this->GetName() );
	OutputLogTo( file_name.c_str(), "\treturn *( x** )( this + script_property->offset ); \\\n" );
	OutputLogTo( file_name.c_str(), "}\n" );

	OutputLogTo( file_name.c_str(), "namespace UnrealScript\n" );
	OutputLogTo( file_name.c_str(), "{\n" );

	if( class_scriptclass->super() )
		OutputLogTo( file_name.c_str(), "\tclass %s : public %s\n", class_scriptclass->GetName(), class_scriptclass->super()->GetName() );
	else
		OutputLogTo( file_name.c_str(), "\tclass %s\n", class_scriptclass->GetName() );

	OutputLogTo( file_name.c_str(), "\t{\n" );
	OutputLogTo( file_name.c_str(), "\tpublic:\n" );

	for( int i = 0; i < object_array()->count(); i++ )
	{
		ScriptObject *object = ( *object_array() )( i );
		
		if( object && object->outer() == this )
		{
			if( !strcmp( object->object_class()->GetName(), "ObjectProperty" ) )
			{
				ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( object );
				OutputLogTo( file_name.c_str(), "\t\t\tADD_OBJECT( %s, %s )\n", object_property->property_class->GetName(), object->GetName() );
			}
			else if( !strcmp( object->object_class()->GetName(), "ByteProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "IntProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "FloatProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "BoolProperty" ) )
			{
				ScriptBoolProperty *bool_property = ( ScriptBoolProperty* )( object );
				OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0x%X )\n", object->object_class()->GetName(), object->GetName(), bool_property->bit_mask );
			}
			else if( !strcmp( object->object_class()->GetName(), "StrProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "StringRefProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_OBJECT( void, %s )\n", object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "ClassProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_OBJECT( ScriptClass, %s )\n", object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "NameProperty" ) ) OutputLogTo( file_name.c_str(), "\t\t\tADD_VAR( ::%s, %s, 0xFFFFFFFF )\n", object->object_class()->GetName(), object->GetName() );
			else if( !strcmp( object->object_class()->GetName(), "StructProperty" ) ) 
			{
				ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( object );
				if( !strcmp( object_property->property_class->GetName(), "Vector" ) )
					OutputLogTo( file_name.c_str(), "\t\t\tADD_STRUCT( ::VectorProperty, %s, 0xFFFFFFFF )\n", object->GetName() );
				else if( !strcmp( object_property->property_class->GetName(), "Rotator" ) )
					OutputLogTo( file_name.c_str(), "\t\t\tADD_STRUCT( ::RotatorProperty, %s, 0xFFFFFFFF )\n", object->GetName() );
			}
			else if( !strcmp( object->object_class()->GetName(), "Function" ) ) 
			{
				bool return_val = false;
				std::string return_type;

				ScriptFunction *script_function = ( ScriptFunction* )( object );
				for( ScriptProperty *script_property = ( ScriptProperty* )( script_function->children() ); script_property; script_property = ( ScriptProperty* )( script_property->next() ) )
				{
					if( script_property->property_flags & ScriptProperty::kPropReturnParm )
					{
						if( !strcmp( script_property->object_class()->GetName(), "ObjectProperty" ) )
						{
							ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( script_property );
							std::string type = "class ";
							type += object_property->property_class->GetName();
							type += "*";
							return_type = type.c_str();
						}
						else if( !strcmp( script_property->object_class()->GetName(), "ByteProperty" ) ) return_type = "byte";
						else if( !strcmp( script_property->object_class()->GetName(), "IntProperty" ) ) return_type = "int";
						else if( !strcmp( script_property->object_class()->GetName(), "FloatProperty" ) ) return_type = "float";
						else if( !strcmp( script_property->object_class()->GetName(), "BoolProperty" ) ) return_type = "bool";
						else if( !strcmp( script_property->object_class()->GetName(), "StrProperty" ) ) return_type = "ScriptArray< wchar_t >";
						else if( !strcmp( script_property->object_class()->GetName(), "StringRefProperty" ) ) return_type = "void*";
						else if( !strcmp( script_property->object_class()->GetName(), "NameProperty" ) ) return_type = "ScriptName";
						else if( !strcmp( script_property->object_class()->GetName(), "ClassProperty" ) ) return_type = "ScriptClass*";
						else if( !strcmp( script_property->object_class()->GetName(), "StructProperty" ) )
						{
							ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( script_property );
							if( !strcmp( object_property->property_class->GetName(), "Vector" ) )
								return_type = "Vector";
							else if( !strcmp( object_property->property_class->GetName(), "Rotator" ) )
								return_type = "Rotator";
							else
								return_type = "void*";
						}
						else
						{
							return_type = "void*";
						}

						return_val = true;

						break;
					}
				}

				int param_size = 0;

				if( !return_val )
					OutputLogTo( file_name.c_str(), "\t\t\tvoid " );
				else
					OutputLogTo( file_name.c_str(), "\t\t\t%s ", return_type.c_str() );

				OutputLogTo( file_name.c_str(), "%s( ", object->GetName() );
				
				std::deque< FuncArg > arg_list;

				for( ScriptProperty *script_property = ( ScriptProperty* )( script_function->children() ); script_property; script_property = ( ScriptProperty* )( script_property->next() ) )
				{
					if( script_property->property_flags & ScriptProperty::kPropParm && !( script_property->property_flags & ScriptProperty::kPropReturnParm ) )
					{
						bool out_param = ( script_property->property_flags & ScriptProperty::kPropOutParm ) != 0;

						std::string property_name = script_property->GetName();

						for( DWORD i = 0; i < arg_list.size(); i++ )
						{
							if( arg_list[ i ].name == property_name )
								property_name += "_";
						}

						if( !strcmp( script_property->object_class()->GetName(), "ObjectProperty" ) )
						{
							ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( script_property );
							std::string type = "class ";
							type += object_property->property_class->GetName();
							type += "*";
							arg_list.push_back( FuncArg( property_name, type, script_property->offset, out_param ) );
						}
						else if( !strcmp( script_property->object_class()->GetName(), "ByteProperty" ) ) arg_list.push_back( FuncArg( property_name, "byte", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "IntProperty" ) ) arg_list.push_back( FuncArg( property_name, "int", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "FloatProperty" ) ) arg_list.push_back( FuncArg( property_name, "float", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "BoolProperty" ) ) arg_list.push_back( FuncArg( property_name, "bool", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "StrProperty" ) ) arg_list.push_back( FuncArg( property_name, "ScriptArray< wchar_t >", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "StringRefProperty" ) ) arg_list.push_back( FuncArg( property_name, "void*", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "NameProperty" ) ) arg_list.push_back( FuncArg( property_name, "ScriptName", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "ClassProperty" ) ) arg_list.push_back( FuncArg( property_name, "ScriptClass*", script_property->offset, out_param ) );
						else if( !strcmp( script_property->object_class()->GetName(), "StructProperty" ) )
						{
							ScriptObjectProperty *object_property = ( ScriptObjectProperty* )( script_property );
							if( !strcmp( object_property->property_class->GetName(), "Vector" ) )
								arg_list.push_back( FuncArg( property_name, "Vector", script_property->offset, out_param ) );
							else if( !strcmp( object_property->property_class->GetName(), "Rotator" ) )
								arg_list.push_back( FuncArg( property_name, "Rotator", script_property->offset, out_param ) );
							else
								arg_list.push_back( FuncArg( property_name, "void*", script_property->offset, out_param ) );
						}

						param_size += script_property->element_size;
					}
				}

				for( DWORD i = 0; i < arg_list.size(); i++ )
				{
					if( arg_list[ i ].out_param )
					{
						if( i < arg_list.size() - 1 )
							OutputLogTo( file_name.c_str(), "%s &%s, ", arg_list[ i ].type.c_str(), arg_list[ i ].name.c_str() );
						else
							OutputLogTo( file_name.c_str(), "%s &%s", arg_list[ i ].type.c_str(), arg_list[ i ].name.c_str() );
					}
					else
					{
						if( i < arg_list.size() - 1 )
							OutputLogTo( file_name.c_str(), "%s %s, ", arg_list[ i ].type.c_str(), arg_list[ i ].name.c_str() );
						else
							OutputLogTo( file_name.c_str(), "%s %s", arg_list[ i ].type.c_str(), arg_list[ i ].name.c_str() );
					}
				}

				OutputLogTo( file_name.c_str(), " )\n\t\t\t{\n" );
				OutputLogTo( file_name.c_str(), "\t\t\t\tstatic ScriptFunction *function = ScriptObject::Find< ScriptFunction >( \"%s\" );\n", object->GetFullName() );
				OutputLogTo( file_name.c_str(), "\t\t\t\tbyte *params = ( byte* )( malloc( %i ) );\n", param_size );

				for( DWORD i = 0; i < arg_list.size(); i++ )
				{
					OutputLogTo( file_name.c_str(), "\t\t\t\t*( %s* )( params + %i ) = %s;\n", arg_list[ i ].type.c_str(), arg_list[ i ].offset, arg_list[ i ].name.c_str() );
				}

				OutputLogTo( file_name.c_str(), "\t\t\t\tScriptObject *object = ( ScriptObject* )( this );\n" );
				OutputLogTo( file_name.c_str(), "\t\t\t\tobject->ProcessEvent( function, params, NULL );\n" );

				for( DWORD i = 0; i < arg_list.size(); i++ )
				{
					if( arg_list[ i ].out_param )
						OutputLogTo( file_name.c_str(), "\t\t\t\t%s = *( %s* )( params + %i );\n", arg_list[ i ].name.c_str(), arg_list[ i ].type.c_str(), arg_list[ i ].offset );
				}

				if( return_val )
				{
					OutputLogTo( file_name.c_str(), "\t\t\t\treturn *( %s* )( params + function->return_val_offset() );\n", return_type.c_str() );
				}

				OutputLogTo( file_name.c_str(), "\t\t\t}\n\n" );

			}
		}
	}
	OutputLogTo( file_name.c_str(), "\t};\n" );
	OutputLogTo( file_name.c_str(), "}\n\n" );

	OutputLogTo( file_name.c_str(), "#undef ADD_VAR\n" );
	OutputLogTo( file_name.c_str(), "#undef ADD_STRUCT\n" );
	OutputLogTo( file_name.c_str(), "#undef ADD_OBJECT\n" );

	ScriptClass *core_class = ScriptObject::Find< ScriptClass >( "Class Core.Class" );
	for( int i = 0; i < object_array()->count(); i++ )
	{
		ScriptObject *class_object = ( *object_array() )( i );
		ScriptClass *class_scriptclass = ( ScriptClass* )( class_object );

		if( class_object && class_object->object_class() == core_class && class_scriptclass->super() == this
			&& strcmp( class_object->outer()->GetName(), "UnrealEd" )
			&& strcmp( class_object->GetName(), "GenericBrowserType_GFxMovie" )
			&& strcmp( class_object->GetName(), "TrRank" )
			)
		{
			class_object->GenerateHeader();
		}
	}
}

void ScriptObject::GenerateHeaders()
{
	InitLoggingTo( "..\\..\\..\\src\\TribesAscendSDK\\HeaderDump\\HeaderDump.h" );
	
	Find< ScriptObject >( "Class Core.Object" )->GenerateHeader();

	OutputLog( "Finished.\n" );
}

char *ScriptObject::GetName()
{
	return name().GetName();
}

const char *ScriptObject::GetFullName()
{
	if( object_class() && outer() )
	{
		static std::string full_name;
		full_name = GetName();

		for( ScriptObject *object_outer = outer(); object_outer != NULL; object_outer = object_outer->outer() )
		{
			full_name.insert( 0, "." );
			full_name.insert( 0, object_outer->GetName() );
		}

		full_name.insert( 0, " " );
		full_name.insert( 0, object_class()->GetName() );

		return full_name.c_str();
	}

	return "Failed to get name";
}



ScriptArray< ScriptObject* > *ScriptObject::object_array_ = NULL;
ScriptArray< ScriptNameEntry* > *ScriptName::name_array_ = NULL;