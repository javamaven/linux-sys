//- ------------------------------------------------------------------
//-    Copyright (c) James W. Grenning -- All Rights Reserved         
//-    For use by owners of Test-Driven Development for Embedded C,   
//-    and attendees of Renaissance Software Consulting, Co. training 
//-    classes.                                                       
//-                                                                   
//-    Available at http://pragprog.com/titles/jgade/                 
//-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3               
//-                                                                   
//-    Authorized users may use this source code in your own          
//-    projects, however the source code may not be used to           
//-    create training material, courses, books, articles, and        
//-    the like. We make no guarantees that this source code is       
//-    fit for any purpose.                                           
//-                                                                   
//-    www.renaissancesoftware.net james@renaissancesoftware.net      
//- ------------------------------------------------------------------

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineArguments.h"
#include "CppUTest/TestRegistry.h"
#include "CppUTest/UtestMacros.h"

TEST_GROUP(CJSON)
{
	

	void setup()
	{
		
	}
	void teardown()
	{
		
	}

	
};

TEST(CJSON, Create)
{
  CHECK(1);
  CHECK_TRUE(1);
}

