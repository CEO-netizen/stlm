## STLM - Simple Todo List Manager
==========================
### Overview
STLM is a simple command-line Todo List Manager. It allows users to add, remove, and mark tasks as completed.

### Features
- Add tasks
- Remove tasks
- Mark tasks as completed
- List all tasks
- Save and exit
- Exit without saving
- Delete todo file

### Usage
1. Run the compiled binary.
2. Add task.
3. List tasks.
4. Mark task as done.
5. Remove task.
6. Save and exit.
7. Exit without saving changes.
8. Dry run test (shows what would be saved without making changes).
9. Delete todo history file.

### New Features

#### Exit Without Saving
- Option 7 allows you to exit the program without saving any changes made during the current session.
- A confirmation prompt will appear to prevent accidental data loss.

### Example Usage
```bash
# Run the program
./stlm

# Add a new task
Choose: 1
Enter task description: Buy groceries

# List all tasks
Choose: 2

# Exit without saving changes
Choose: 7
```

### DISCLAIMER
This project is licensed under the **GNU General Public License v3.0**. Please see the LICENSE file for more information.
