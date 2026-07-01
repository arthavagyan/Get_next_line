# 📜 Get_next_line — Reading a line from a FD is finally easy

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42" alt="Score 125/100" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language C" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge" alt="Status Completed" />
</p>

---

## 📖 Description

**get_next_line** is a famous project in the **42 curriculum**. The task is simple but challenging: create a function that reads one line at a time from a file descriptor (FD). 

It helps you understand how memory works in C, how to use **static variables**, and how to manage the heap efficiently.

---

## 🎯 Project Goal

The goal is to write a function that:
- Returns a single line from a file descriptor.
- Works with **files**, **standard input (stdin)**, and **redirections**.
- Returns the line including the `\n` character.
- Returns `NULL` when there is nothing left to read or if an error happens.

---

## 🛠️ How to Compile

You must compile the project with a specific flag to define the `BUFFER_SIZE`. This tells the function how many characters to read at once.

**Example command:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

---

## 🧠 Algorithm: Why Static Variables?

I chose the **Static Buffer Persistence** approach. Here is why:

### 1. Data Preservation 💾
The `read()` function often reads more characters than one line. A **static variable** acts like a "storage room" (or stash). It saves the extra characters so they are ready for the next time you call the function.

### 2. Simple Logic 🔄
The algorithm follows a clear process:
1. **Read** from the file until we find a `\n` or reach the end.
2. **Extract** the current line to return it.
3. **Clean** the stash to keep only the leftovers for the next call.

---

## 📂 Project Structure

| File | Description |
| :--- | :--- |
| `get_next_line.c` | Main logic of the function. |
| `get_next_line_utils.c` | Helper functions (like `strlen`, `strjoin`, etc.). |
| `get_next_line.h` | Header file with prototypes and macros. |

---

## 📚 Resources

- **Man 3 read** — Learning how to read files.
- **Static Variables** — Understanding how they stay in memory.
- **42 Intranet** — Project guidelines.
- **Peer Learning** — Discussing logic with classmates.
- **AI Tools** — Used for searching documentation and debugging.

---

## 👨‍💻 Author

Created by **artavagy** as part of the 42 Yerevan curriculum.

<div align="center">

  [![GitHub Profile](https://img.shields.io/badge/GitHub-artavagy-181717?style=for-the-badge&logo=github)](https://github.com/arthavagyan)

</div>

---
