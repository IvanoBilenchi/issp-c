# Instructions

This folder contains a collection of vulnerable C programs that accept some user input
and execute some very simple functionality.

Generally speaking, your goal is to find out which flaws affect each program,
how they can be fixed, and how they can be exploited by providing carefully crafted input
to carry out a specific task, such as leaking some data or executing a malicious function.

Specific instructions for each program are provided through comments on top of the .c source file.

## General information

- You can ignore statements starting with `dlog_`, they are part of the debug logging system.
- Each executable accepts a `-d` or `--debug` flag, which allows you to see some useful
  debugging information concerning the layout of data and functions.
- User input can be provided as ASCII text, or individual bytes can be specified by encoding
  each byte as a backslash `\` followed by one or two hexadecimal characters.

  **Example input:** 16 bytes made of 8 ASCII characters and 8 hex bytes -
  `abcdefgh\0\1\2\3\10\11\12\13`
