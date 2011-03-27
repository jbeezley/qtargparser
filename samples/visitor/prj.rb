require 'rubygems'

gem 'Mxx_ru', '>= 1.4.7'

require 'mxx_ru/cpp/qt4'

Mxx_ru::Cpp::exe_target {

		rtl_mode( Mxx_ru::Cpp::RTL_SHARED )
		rtti_mode( Mxx_ru::Cpp::RTTI_ENABLED )
		threading_mode( Mxx_ru::Cpp::THREADING_MULTI )

		qt = generator( MxxRu::Cpp::Qt4.new( self ) )

		target( "samples/visitor/visitor" )

		cpp_source( "main.cpp" )
}
