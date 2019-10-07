
/*
  @author: Nikita Mogilevsky
  @email: nikitamog@bellevuecollege.edu
  @description:
  This file contains generic tests for Strong Check exceptions
  among others that may come up in the future.
*/

// used as a type parameter for generic datatypes
// e.g. LinkedList<TestClass>
/*struct TestClass
{
    TestClass(int v = 0)
        : p(thisCanThrow(), new int(v)) {}
    TestClass(const TestClass& rStruct)
        : p(thisCanThrow(), new int(*rStruct.p)) {}
    const TestClass& operator=(const TestClass& rStruct)
        {
            thisCanThrow();
            *p = *rStruct.p;
        }
    const bool operator==(const TestClass& rStruct)
        {
            thisCanThrow();
            return *p == rStruct.p;
        }
    ~TestClass() { delete p; }
};
*/
