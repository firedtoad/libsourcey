//
// This software is copyright by Sourcey <mail@sourcey.com> and is distributed under a dual license:
// Copyright (C) 2005 Sourcey
//
// Non-Commercial Use:
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 
// Commercial Use:
// Please contact mail@sourcey.com
//


#include "Sourcey/TURN/FiveTuple.h"


using namespace std;


namespace Sourcey {
namespace TURN {


FiveTuple::FiveTuple() : 
	_transport(Net::UDP) 
{
}


FiveTuple::FiveTuple(const Net::Address& remote, const Net::Address& local, Net::TransportProtocol transport) : 
	_remote(remote), _local(local), _transport(transport) 
{
}


FiveTuple::FiveTuple(const FiveTuple& r) :
	_remote(r._remote), _local(r._local), _transport(r._transport)
{
}


bool FiveTuple::operator ==(const FiveTuple& r) const {
	return _remote == r._remote && 
		_local == r._local && 
		_transport == r._transport;
}


bool FiveTuple::operator <(const FiveTuple& r) const 
{
	if (_remote.port() < r._remote.port())
		return true;
	if (r._remote.port() < _remote.port())
		return false;
	if (_local.port() < r._local.port())
		return true;
	if (r._local.port() < _local.port())
		return false;
	return false;
}


string FiveTuple::toString() const 
{ 
    ostringstream ost;
	ost << "FiveTuple[" 
		<< _remote.toString() << ":" 
		<< _local.toString() << ":" 
		<< _transport 
		<< "]";
    return ost.str();
}


} } // namespace Sourcey::TURN