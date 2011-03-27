
/*!
	\file
	\author Igor P. Mironchik (imironchick at gmail dot com).

	Copyright (c) 2010-2011 Igor P. Mironchik

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
	// test_complex_1
	//

	UNIT_START( test_complex_1 )

		QStringList arguments;
		arguments << "test" << "-a" << "1" << "--bb" << "2"
			<< "--cc" << "3" << "-d" << "4"
			<< "-e" << "-f" << "-g" << "-i" << "5";

		QtArgCmdLine cmd( arguments );

		QtArg a( 'a', QString(), QString(), false, true );
		QtArg b( QString::fromLatin1( "bb" ), QString(), false, true );
		QtArg c( QString::fromLatin1( "cc" ), QString(), false, true );
		QtArg d( 'd', QString(), QString(), false, true );
		QtArg e( 'e', QString(), QString(), false, false );
		QtArg f( 'f', QString(), QString(), false, false );
		QtArg g( 'g', QString(), QString(), false, false );
		QtArg i( 'i', QString(), QString(), false, true );

		cmd.addArg( a );
		cmd.addArg( b );
		cmd.addArg( c );
		cmd.addArg( d );
		cmd.addArg( e );
		cmd.addArg( f );
		cmd.addArg( g );
		cmd.addArg( i );

		cmd.parse();

		CHECK_CONDITION( a.value().toString() == "1" )
		CHECK_CONDITION( b.value().toString() == "2" )
		CHECK_CONDITION( c.value().toString() == "3" )
		CHECK_CONDITION( d.value().toString() == "4" )
		CHECK_CONDITION( e.value().toBool() == true )
		CHECK_CONDITION( f.value().toBool() == true )
		CHECK_CONDITION( g.value().toBool() == true )
		CHECK_CONDITION( i.value().toString() == "5" )

	UNIT_FINISH( test_complex_1 )


	//
	// test_complex_2
	//

	UNIT_START( test_complex_2 )

	QStringList arguments;
	arguments << "test" << "-a" << "1" << "--bb" << "2"
		<< "--cc=3" << "-d4" << "-ef" << "-gi5";

	QtArgCmdLine cmd( arguments );

	QtArg a( 'a', QString(), QString(), false, true );
	QtArg b( QString::fromLatin1( "bb" ), QString(), false, true );
	QtArg c( QString::fromLatin1( "cc" ), QString(), false, true );
	QtArg d( 'd', QString(), QString(), false, true );
	QtArg e( 'e', QString(), QString(), false, false );
	QtArg f( 'f', QString(), QString(), false, false );
	QtArg g( 'g', QString(), QString(), false, false );
	QtArg i( 'i', QString(), QString(), false, true );

	cmd.addArg( a );
	cmd.addArg( b );
	cmd.addArg( c );
	cmd.addArg( d );
	cmd.addArg( e );
	cmd.addArg( f );
	cmd.addArg( g );
	cmd.addArg( i );

	cmd.parse();

	CHECK_CONDITION( a.value().toString() == "1" )
	CHECK_CONDITION( b.value().toString() == "2" )
	CHECK_CONDITION( c.value().toString() == "3" )
	CHECK_CONDITION( d.value().toString() == "4" )
	CHECK_CONDITION( e.value().toBool() == true )
	CHECK_CONDITION( f.value().toBool() == true )
	CHECK_CONDITION( g.value().toBool() == true )
	CHECK_CONDITION( i.value().toString() == "5" )

	UNIT_FINISH( test_complex_2 )

	//
	// test_complex_3
	//

	UNIT_START( test_complex_3 )

	QStringList arguments;
	arguments << "test" << "-a" << "1" << "--bb" << "2"
		<< "--cc=3" << "-d4" << "-efgi" << "5";

	QtArgCmdLine cmd( arguments );

	QtArg a( 'a', QString(), QString(), false, true );
	QtArg b( QString::fromLatin1( "bb" ), QString(), false, true );
	QtArg c( QString::fromLatin1( "cc" ), QString(), false, true );
	QtArg d( 'd', QString(), QString(), false, true );
	QtArg e( 'e', QString(), QString(), false, false );
	QtArg f( 'f', QString(), QString(), false, false );
	QtArg g( 'g', QString(), QString(), false, false );
	QtArg i( 'i', QString(), QString(), false, true );

	cmd.addArg( a );
	cmd.addArg( b );
	cmd.addArg( c );
	cmd.addArg( d );
	cmd.addArg( e );
	cmd.addArg( f );
	cmd.addArg( g );
	cmd.addArg( i );

	cmd.parse();

	CHECK_CONDITION( a.value().toString() == "1" )
	CHECK_CONDITION( b.value().toString() == "2" )
	CHECK_CONDITION( c.value().toString() == "3" )
	CHECK_CONDITION( d.value().toString() == "4" )
	CHECK_CONDITION( e.value().toBool() == true )
	CHECK_CONDITION( f.value().toBool() == true )
	CHECK_CONDITION( g.value().toBool() == true )
	CHECK_CONDITION( i.value().toString() == "5" )

	UNIT_FINISH( test_complex_3 )

UNIT_TEST_FINISH
