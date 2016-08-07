IRC-CPP
An IRC bot made in C++ using cpIRC
IDE: Codeblocks

Current bugs:
- Since program is written in C++98, range based for loops aren't allowed. Must fix checkCommand()
- Compiler says vectors do not have a .length() method. Docs seem to say otherwise.

Planned features:
- Connect to IRC server automatically on start
- Autojoin channel after MOTD
- Message users with requested information (Info get functions to be added after joining is fixed.)
