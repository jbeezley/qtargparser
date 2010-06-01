require 'rubygems'

gem 'Mxx_ru', '>= 1.4.7'

require 'mxx_ru/cpp'

MxxRu::Cpp::composite_target() {

		required_prj( "test/required_argument_with_option/prj.ut.rb" )
		required_prj( "test/dissallowed_argument_names/prj.ut.rb" )
		required_prj( "test/required_argument/prj.ut.rb" )
		required_prj( "test/flags_composition/prj.ut.rb" )
		required_prj( "test/not_required_argument_with_option/prj.ut.rb" )
		required_prj( "test/not_full_argument_name/prj.ut.rb" )
		required_prj( "test/visitor/prj.ut.rb" )
		required_prj( "test/multiarg/prj.ut.rb" )
		required_prj( "test/xored_arguments/prj.ut.rb" )
		required_prj( "test/constraint/prj.ut.rb" )
}
