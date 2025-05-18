# Deletes all .exe files in the current directory and all subdirectories
import os

for root, dirs, files in os.walk('.'):
    for file in files:
        if file.lower().endswith('.exe'):
            file_path = os.path.join(root, file)
            try:
                os.remove(file_path)
                print(f"Deleted: {file_path}")
            except Exception as e:
                print(f"Failed to delete {file_path}: {e}")
