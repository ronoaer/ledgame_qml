# ledgame
it's implemented by Qt(5, 6)/C++ 17(MacOS 12.6 and Ubuntu 20)
unit test by GTest, please update configuration in file ledgame.pro "include(../../googletest-main/gtest_dependency.pri)"

# description
there are there buttons and labels, and KeySequence.
e.g. Happy Path
Given: Buttons("C", "A", "B"), KeySequence("ABB"), and Label( Led1, Led2, Led3)
When: push "A"
Then: Led3 -> green

When: push "B"
Then: Led3 -> green, Led2 -> green

When: push "B"
Then: Led3 -> green, Led2 -> green, Led1 -> green
Then: Regerate KeySequence, and reset Buttons

![Effect](https://github.com/ronoaer/ledgame/blob/main/ui.png)

![Framework](https://github.com/ronoaer/ledgame/blob/main/framework.png)
Qt/C++

e.g. Sad Path
Given: Buttons("C", "A", "B"), KeySequence("ABB"), and Label( Led1, Led2, Led3)
When: push "C"
Then: Led3 -> red

When: push "A"
Then: Led3 -> yellow, Led2 -> red

When: push "B"
Then: Led3 -> green, Led2 -> yellow, Led1 -> red
Then: Regerate KeySequence, and reset Buttons
