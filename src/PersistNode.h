//                            Package   : omniEvents
// PersistNode.h              Created   : 2004/04/29
//                            Author    : Alex Tingle
//
//    Copyright (C) 2004 Alex Tingle.
//
//    This file is part of the omniEvents application.
//
//    omniEvents is free software; you can redistribute it and/or
//    modify it under the terms of the GNU Lesser General Public
//    License as published by the Free Software Foundation; either
//    version 2.1 of the License, or (at your option) any later version.
//
//    omniEvents is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Lesser General Public License for more details.
//
//    You should have received a copy of the GNU Lesser General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef OMNIEVENTS__PERSIST_NODE_H
#define OMNIEVENTS__PERSIST_NODE_H

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <string>
#include <map>

#ifdef HAVE_IOSTREAM
#  include <iostream>
#else
#  include <iostream.h>
#endif

#ifdef HAVE_STD_IOSTREAM
using namespace std;
#endif

namespace OmniEvents {

class PersistNode;

class PersistNode
{
public:
  PersistNode(){}           ///< Create an empty node.
  PersistNode(istream& is); ///< Create root node and read tree from stream.
  ~PersistNode();           ///< Free node and all its children.
  void   output(ostream& os,string name) const;

public: // Construction
  inline bool  readnode(istream& is);
  inline bool  readtoken(istream& is, string& tok);
  PersistNode* addnode(const string& name);
  void         delnode(const string& name);
  void         addattr(const string& keyvalue);
  void         addattr(const string& key,long value);

public: // Accessors
  bool         hasAttr(const string& key) const;
  string       attrString(const string& key, const string& fallback="") const;
  long         attrLong(  const string& key, long          fallback=0 ) const;
  PersistNode* child(const string& key) const;

public: // Members
  map<string,PersistNode*> _child;
  map<string,string>       _attr;

  friend class omniEventsLog;
};

}; // end namespace OmniEvents

#endif // OMNIEVENTS__PERSIST_NODE_H
