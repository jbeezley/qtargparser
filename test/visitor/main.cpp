
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
#include <QtArg/Visitor>
#include <QtArg/CmdLine>

// Qt include.
#include <QtCore/QString>
#include <QtCore/QStringList>

// unit test helper.
#include <test/helper/helper.hpp>


UNIT_TEST_START

	namespace /* anonymous */ {

		//
		// TestVisitor
		//

		class TestVisitor
			:	public QtArgVisitorIface
		{
			public:
				TestVisitor()
					:	m_visited( false )
				{}

				bool wasVisited() const
				{
					return m_visited;
				}

				void visit( QtArgCmdLineContext & context )
				{
					m_visited = true;
				}

			private:
				bool m_visited;
		}; // class TestVisitor

	} /* namespace anonymous */


	//
	// test_visitor
	//

	UNIT_START( test_visitor )

		const QString argName = QString::fromLatin1( "one" );

		QStringList arguments;
		arguments << "program" << QString::fromLatin1( "--" ) + argName;

		QtArgCmdLine cmd( arguments );

		QtArg one( argName );
		TestVisitor visitor;
		one.setVisitor( &visitor );

		cmd.addArg( one );

		CHECK_CONDITION( one.value().toBool() == false )

		cmd.parse();

		CHECK_CONDITION( one.value().toBool() == true )
		CHECK_CONDITION( visitor.wasVisited() == true )

	UNIT_FINISH( test_visitor )

UNIT_TEST_FINISH
