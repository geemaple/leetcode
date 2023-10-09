import datetime

def update_readme():
    with open("README_test.md", "a") as f:
        f.write(f"Last updated: {datetime.datetime.now()}\n")

if __name__ == "__main__":
    update_readme()