require 'rubygems'

gem 'Mxx_ru', '>= 1.4.7'

require 'mxx_ru/cpp/qt4'

Mxx_ru::Cpp::exe_target {

		rtti_mode( Mxx_ru::Cpp::RTTI_ENABLED )

		qt = generator( MxxRu::Cpp::Qt4.new( self ) )

		target( "test.multiarg" )

		cpp_source( "main.cpp" )
}
