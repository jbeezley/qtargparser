
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
#include <QtArg/Arg>
#include <QtArg/XorArg>
#include <QtArg/CmdLine>
#include <QtArg/Help>

// Qt include.
#include <QtCore/QDebug>


void main( int argc, char ** argv )
{
	try {
		QtArgCmdLine cmd( argc, argv );

		QtArg one( QtArgIface::NamesList() << "one" << "and-one",
			"one description", true, true );
		one.setLongDescription( "This is a long description "
			"of the \"one\" argument." );

		QtArg two( "two", "two description" );

		QtArg a( QtArgIface::FlagsList() << 'a' << 'c' << 'd',
			QtArgIface::NamesList() << "three-flags",
			"three flags description" );

		QtArg b( QtArgIface::FlagsList() << 'b' << 'e' << 'f',
			QtArgIface::NamesList(), "b description", false, true );

		QtXorArg xored( a, b, "xored" );

		QtArgHelp help( &cmd );
		help.printer()->setProgramDescription( "Testing help printing." );
		help.printer()->setExecutableName( argv[0] );

		cmd.addArg( one );
		cmd.addArg( two );
		cmd.addArg( xored );
		cmd.addArg( help );

		cmd.parse();
	}
	catch( const QtArgHelpHasPrintedEx & x )
	{
	}
	catch( const QtArgBaseException & x )
	{
		qDebug() << x.what();
	}
}
