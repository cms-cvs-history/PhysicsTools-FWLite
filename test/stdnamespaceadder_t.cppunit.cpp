/*----------------------------------------------------------------------

Test program for edm::TypeIDBase class.
Changed by Viji on 29-06-2005

$Id: stdnamespaceadder_t.cppunit.cc,v 1.1 2005/12/06 17:06:24 chrjones Exp $
 ----------------------------------------------------------------------*/

#include <cassert>
#include <iostream>
#include <string>
#include <cppunit/extensions/HelperMacros.h>
#include "PhysicsTools/FWLite/src/stdNamespaceAdder.h"

class testSTDNamespaceAdder: public CppUnit::TestFixture
{
CPPUNIT_TEST_SUITE(testSTDNamespaceAdder);

CPPUNIT_TEST(tests);

CPPUNIT_TEST_SUITE_END();
public:
  void setUp(){}
  void tearDown(){}

  void tests();
};

///registration of the test so that the runner can find it
CPPUNIT_TEST_SUITE_REGISTRATION(testSTDNamespaceAdder);

using std::cout;
using std::endl;

void testSTDNamespaceAdder::tests()
{
   using std::string;
   using namespace fwlite;

   static const string kVectorBlahNoNS("vector<Blah>");
   static const string kVectorBlahNS("std::vector<Blah>");
   static const string kTVectorBlah("Tvector<Blah>");
   static const string kVectorVectorBlahNoNS("vector<vector<Blah> >");
   static const string kVectorVectorBlahNS("std::vector<std::vector<Blah> >");

   //cout <<" substitution \""<<kVectorVectorBlahNoNS<<"\" \""
   //     <<stdNamespaceAdder(kVectorVectorBlahNoNS)<<"\""<<endl;

   CPPUNIT_ASSERT(stdNamespaceAdder(kVectorBlahNoNS) == kVectorBlahNS);
   CPPUNIT_ASSERT(stdNamespaceAdder(kVectorBlahNS) == kVectorBlahNS);
   CPPUNIT_ASSERT(stdNamespaceAdder(kTVectorBlah) == kTVectorBlah);
   CPPUNIT_ASSERT(stdNamespaceAdder(kVectorVectorBlahNoNS) == kVectorVectorBlahNS);
   CPPUNIT_ASSERT(stdNamespaceAdder(kVectorVectorBlahNS) == kVectorVectorBlahNS);
   
}
#include <Utilities/Testing/interface/CppUnit_testdriver.icpp>
