// -*- C++ -*-
//
// Package:     FWLite
// Class  :     stdNamespaceAdder
// 
// Implementation:
//     <Notes on implementation>
//
// Original Author:  
//         Created:  Tue Dec  6 09:18:05 EST 2005
// $Id$
//

// system include files
#include "boost/regex.hpp"

// user include files
#include "PhysicsTools/FWLite/src/stdNamespaceAdder.h"


//
// constants, enums and typedefs
//
namespace fwlite {
   std::string stdNamespaceAdder(const std::string& iClassName)
   {
      //adds the std:: prefix to vector, string, map, list or deque if it is not
      // already there
      static const boost::regex e("(^|[^[:alnum:]_:])((?:vector)|(?:string)|(?:map)|(?:list)|(?:deque))");
      const std::string format("\\1std::\\2");
      
      return regex_replace(iClassName, e, format, boost::match_default | boost::format_sed);
   }
}
