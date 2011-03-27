require 'rubygems'

gem 'Mxx_ru', '>= 1.4.7'

require 'mxx_ru/binary_unittest'

Mxx_ru::setup_target(
	Mxx_ru::Binary_unittest_target.new(
		"test/very_similar_names/prj.ut.rb",
		"test/very_similar_names/prj.rb" ) )
