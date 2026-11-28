/******************************************************************************
 *  ActReact.hh
 *
 *  This file is part of ThiefLib, a library for Thief 1/2 script modules.
 *  Copyright (C) 2013-2014 Kevin Daughtridge <kevin@kdau.com>
 *  Adapted in part from Public Scripts and the Object Script Library
 *  Copyright (C) 2005-2013 Tom N Harris <telliamed@whoopdedo.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#ifndef THIEF_ACTREACT_HH
#define THIEF_ACTREACT_HH

#include <Thief/Base.hh>
#include <Thief/Object.hh>

namespace Thief {



struct Reaction
{
	typedef long Number;
	static const Reaction NONE;
	Number number;

	Reaction ();
	explicit Reaction (Number);
	explicit Reaction (const String& name); //TESTME

	bool operator == (const Reaction&) const;
	bool operator != (const Reaction&) const;
	bool operator < (const Reaction&) const;

	String get_name () const; //TESTME
};



class Stimulus : public virtual Object
{
public:
	THIEF_OBJECT_TYPE (Stimulus)

	bool is_stimulus () const;

	THIEF_PROP_FIELD (bool, causes_blood); //TESTME
	THIEF_PROP_FIELD (bool, causes_knockout); //TESTME
};



class Reagent : public virtual Object
{
public:
	THIEF_OBJECT_TYPE (Reagent)

	void stimulate (const Stimulus&, float intensity,
		const Object& source = Object::NONE);

	void subscribe_stimulus (const Stimulus&); //TESTME
	void unsubscribe_stimulus (const Stimulus&); //TESTME
};



} // namespace Thief

#include <Thief/ActReact.inl>

#endif // THIEF_ACTREACT_HH

