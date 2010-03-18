
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

	UNIT_FINISH( test_multiarg )

UNIT_TEST_FINISH
