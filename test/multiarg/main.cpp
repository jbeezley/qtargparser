
/*!
	\file

	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2010-2012 Igor Mironchik

	Permission is hereby granted, free of charge, to any person
	obtaining a copy of this software and associated documentation
	files (the "Software"), to deal in the Software without
	restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following
	conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.
*/

// QtArg include.
#include <QtArg/MultiArg>
#include <QtArg/CmdLine>

// Qt include.
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QList>

// unit test helper.
#include <test/helper/helper.hpp>


UNIT_TEST_START

	//
	// test_multiarg
	//

	UNIT_START( test_multiarg )

		const QString firstValue = QString::fromLatin1( "first" );
		const QString secondValue = QString::fromLatin1( "second" );

		QStringList arguments;
		arguments << "program" << "-a" << firstValue << "-a" << secondValue;

		QtArgCmdLine cmd( arguments );

		QtMultiArg one( 'a' );
		one.setWithValue( true );

		cmd.addArg( one );

		CHECK_CONDITION( one.value().toList().size() == 0 )

		cmd.parse();

		CHECK_CONDITION( one.value().toList().size() == 2 )

		CHECK_CONDITION ( one.value().toList().front().toString() == firstValue )
		CHECK_CONDITION ( one.value().toList().back().toString() == secondValue )
		CHECK_CONDITION( one.count() == 2 )

	UNIT_FINISH( test_multiarg )


	//
	// test_count_in_multiarg_1
	//

	UNIT_START( test_count_in_multiarg_1 )

		QStringList arguments;
		arguments << "program" << "-a" << "-a";

		QtArgCmdLine cmd( arguments );

		QtMultiArg one( 'a' );

		cmd.addArg( one );

		CHECK_CONDITION( one.value().toList().size() == 0 )

		cmd.parse();

		CHECK_CONDITION( one.value().toBool() == true )
		CHECK_CONDITION( one.isDefined() == true )
		CHECK_CONDITION( one.count() == 2 )

	UNIT_FINISH( test_count_in_multiarg_1 )


	//
	// test_count_in_multiarg_2
	//

	UNIT_START( test_count_in_multiarg_2 )

		QStringList arguments;
		arguments << "program" << "-a" << "-a";

		QtArgCmdLine cmd( arguments );

		QtMultiArg one( 'a' );

		cmd.addArg( one );

		CHECK_CONDITION( one.value().toList().size() == 0 )

		cmd.parse();

		CHECK_CONDITION( one.value().toBool() == true )
		CHECK_CONDITION( one.isDefined() == true )
		CHECK_CONDITION( one.count() == 2 )

	UNIT_FINISH( test_count_in_multiarg_2 )


	//
	// test_count_in_multiarg_3
	//

	UNIT_START( test_count_in_multiarg_3 )

		QStringList arguments;
		arguments << "program" << "-a" << "3";

		QtArgCmdLine cmd( arguments );

		QtMultiArg one( 'a' );

		cmd.addArg( one );

		CHECK_CONDITION( one.value().toList().size() == 0 )

		cmd.parse();

		CHECK_CONDITION( one.value().toBool() == true )
		CHECK_CONDITION( one.isDefined() == true )
		CHECK_CONDITION( one.count() == 3 )

	UNIT_FINISH( test_count_in_multiarg_3 )


	//
	// test_count_in_multiarg_4
	//

	UNIT_START( test_count_in_multiarg_4 )

		QStringList arguments;
		arguments << "program" << "-a4";

		QtArgCmdLine cmd( arguments );

		QtMultiArg one( 'a' );

		cmd.addArg( one );

		CHECK_CONDITION( one.value().toList().size() == 0 )

		cmd.parse();

		CHECK_CONDITION( one.value().toBool() == true )
		CHECK_CONDITION( one.isDefined() == true )
		CHECK_CONDITION( one.count() == 4 )

	UNIT_FINISH( test_count_in_multiarg_4 )


	//
	// test_count_in_multiarg_5
	//

	UNIT_START( test_count_in_multiarg_5 )

		QStringList arguments;
		arguments << "program" << "-a=5";

		QtArgCmdLine cmd( arguments );

		QtMultiArg one( 'a' );

		cmd.addArg( one );

		CHECK_CONDITION( one.value().toList().size() == 0 )

		cmd.parse();

		CHECK_CONDITION( one.value().toBool() == true )
		CHECK_CONDITION( one.isDefined() == true )
		CHECK_CONDITION( one.count() == 5 )

	UNIT_FINISH( test_count_in_multiarg_5 )


	//
	// test_not_defined_multiarg
	//

	UNIT_START( test_not_defined_multiarg )

		QStringList arguments;
		arguments << "program" << "-a" << "-a";

		QtArgCmdLine cmd( arguments );

		QtMultiArg one( 'a' );
		QtMultiArg two( 'b' );

		cmd.addArg( one );
		cmd.addArg( two );

		CHECK_CONDITION( one.value().toBool() == false )
		CHECK_CONDITION( two.value().toBool() == false )

		cmd.parse();

		CHECK_CONDITION( one.value().toBool() == true )
		CHECK_CONDITION( one.isDefined() == true )
		CHECK_CONDITION( one.count() == 2 )

		CHECK_CONDITION( two.value().toBool() == false )
		CHECK_CONDITION( two.isDefined() == false )
		CHECK_CONDITION( two.isPresent() == false )
		CHECK_CONDITION( two.count() == 0 )

	UNIT_FINISH( test_not_defined_multiarg )

UNIT_TEST_FINISH
