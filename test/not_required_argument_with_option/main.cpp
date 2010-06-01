
/*!
	\file
	\author Igor P. Mironchik (imironchick at gmail dot com).

	Copyright (c) 2009 Igor P. Mironchik

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
#include <QtArg/Arg>
#include <QtArg/CmdLine>

// Qt include.
#include <QtCore/QString>
#include <QtCore/QStringList>

// unit test helper.
#include <test/helper/helper.hpp>


UNIT_TEST_START

	//
	// test_not_required_argument_with_option_that_not_defined
	//

	UNIT_START( test_not_required_argument_with_option_that_not_defined )

		QStringList arguments;
		arguments << "program";

		QtArgCmdLine cmd( arguments );

		QtArg one( 'o', QString::fromLatin1( "one" ),
			QString::fromLatin1( "It's our not required argument with option" ),
			false, true );

		cmd.addArg( one );

		cmd.parse();

		CHECK_CONDITION( one.isDefined() == false )
		CHECK_CONDITION( one.value().toString().isEmpty() )

	UNIT_FINISH( test_not_required_argument_with_option_that_not_defined )


	//
	// test_not_required_argument_with_option
	//

	UNIT_START( test_not_required_argument_with_option )

		const QString value = QString::fromLatin1( "value" );
		QStringList arguments;
		arguments << "program" << "--one" << value;

		QtArgCmdLine cmd( arguments );

		QtArg one( QString::fromLatin1( "one" ),
			QString::fromLatin1( "It's our not required argument with option" ),
			false, true );

		cmd.addArg( one );

		CHECK_CONDITION( one.value().toString().isEmpty() )

		cmd.parse();

		CHECK_CONDITION( one.value().toString() == value )

	UNIT_FINISH( test_not_required_argument_with_option )


	//
	// test_not_required_argument_that_defined_with_option_that_not_defined
	//

	UNIT_START( test_not_required_argument_that_defined_with_option_that_not_defined )

		QStringList arguments;
		arguments << "program" << "--one";

		QtArgCmdLine cmd( arguments );

		QtArg one( QString::fromLatin1( "one" ),
			QString::fromLatin1( "It's our not required argument with option" ),
			false, true );

		cmd.addArg( one );

		CHECK_CONDITION( one.value().toString().isEmpty() )

		CHECK_THROW( QtArgNotDefinedOptionForTheArgumentEx, cmd.parse(); )

	UNIT_FINISH( test_not_required_argument_that_defined_with_option_that_not_defined )

UNIT_TEST_FINISH