
/*!
	\file
	\brief Help printer.

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

#ifndef QTARG__HELPIFACE_HPP__INCLUDED
#define QTARG__HELPIFACE_HPP__INCLUDED

// Qt include.
#include <QtCore/QString>
#include <QtCore/QStringList>

// QtArg include.
//#include "arg.hpp"


//
// isUnique
//

//! \return Is name \par name unique in names \par list.
inline bool
isUnique( const QString & name, const QStringList & list )
{
	bool contains = false;

	foreach( QString n, list )
		if( n.startsWith( name ) )
		{
			if( !contains )
				contains = true;
			else
				return false;
		}

	return true;
} // isUnique


//
// markUnrequiredPartOfTheName
//

/*!
	Mark unrequired part of the name with '[' and ']'
	characters.
*/
inline void
markUnrequiredPartOfTheName( QString & name,
	const QStringList & rawNames )
{
	int index = 1;

	while( !isUnique( name.left( index ), rawNames )
		&& index < name.length() )
			++index;

	if( index != name.length() )
	{
		name.insert( index, '[' );
		name.append( ']' );
	}
} // markUnrequiredPartOfTheName


//
// QtArgHelpPrinterIface
//

//! Interface for the help printer.
class QtArgHelpPrinterIface {
	protected:
		virtual ~QtArgHelpPrinterIface() {}

	public:
		//! Print help.
		virtual void print() const = 0;

		/*!
			Set program description that will be used
			as first line in the help.
		*/
		virtual void setProgramDescription( const QString & desc ) = 0;

		/*!
			Set executable name that defined in argv[0]
			or something else.
		*/
		virtual void setExecutableName( const QString & exec ) = 0;

		/*!
			Set "USAGE" string.
		*/
		virtual void setUsageString( const QString & usage ) = 0;

		/*!
			Set "HELP" string.
		*/
		virtual void setHelpString( const QString & help ) = 0;

		/*!
			Set delimiter character.
		*/
		virtual void setDelimiterChar( const QChar & delim ) = 0;

	public:
		/*!
			\name This constants will be replaced with
			correct spaces, commas and so on.

			\li beforeFlags - space before flags. Usually it's a
				constant, somewhere 1 blank space.

			\li afterFlags - space after flags and ','.
				This is a variable length blank space with comma.
				It may looks like this: ", ". The length of blank
				space depends on max length of the flags string
				and argValue length if it presents. argValue will
				present after flags string if there is no argument's
				names for this argument.

			\li namesSeparator - String between names. It can be
				like this one: ", ".

			\li beforeNames - space before names. Equals to
				beforeFlags + longest flags string. This constant
				should be used if argument doesn't have any flags
				and only names. This guarantee that names will
				shown in necessary column.

			\li beforeDescription - space before description.

			\li flagMarker - is a character used to specify flag.

			\li nameMarker - is a doubled flagMarker.
		*/
		//! \{

			static const QString beforeFlags;

			static const QString afterFlags;

			static const QString namesSeparator;

			static const QString beforeNames;

			static const QString beforeDescription;

			static const QString flagMarker;

			static const QString nameMarker;

		//! \}

		//! New line in help string.
		static const QString newLine;
		//! String with value of the argument.
		static const QString argValue;
}; // class QtArgHelpPrinterIface

const QString QtArgHelpPrinterIface::beforeFlags =
	QLatin1String( "%beforeFlags%" );

const QString QtArgHelpPrinterIface::afterFlags =
	QLatin1String( "%afterFlags%" );

const QString QtArgHelpPrinterIface::namesSeparator =
	QLatin1String( "%namesSeparator%" );

const QString QtArgHelpPrinterIface::beforeNames =
	QLatin1String( "%beforeNames%" );

const QString QtArgHelpPrinterIface::beforeDescription =
	QLatin1String( "%beforeDescription%" );

const QString QtArgHelpPrinterIface::newLine =
	QLatin1String( "%newLine%" );

const QString QtArgHelpPrinterIface::argValue =
	QLatin1String( "%value%" );

const QString QtArgHelpPrinterIface::flagMarker =
	QLatin1String( "%flagMarker%" );

const QString QtArgHelpPrinterIface::nameMarker =
	QLatin1String( "%nameMarker%" );

#endif // QTARG__HELPIFACE_HPP__INCLUDED
