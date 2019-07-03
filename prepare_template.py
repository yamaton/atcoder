import pathlib
import sys
import shutil
import fire


def prepare_template(s, count=4, ext=".cc"):
    p = pathlib.Path(s)
    if p.exists():
        print(f"{s} already exists!")
        sys.exit()

    src = p.parent / "templates" / ("template" + ext)
    assert src.exists(), "template file not found!"

    p.mkdir()
    print(f"Created {p}")
    problems = "abcdef"[:count]
    for c in problems:
        dst = p / (s + "_" + c + ext)
        shutil.copy2(src, dst)
        print(f"Copied from {src} to {dst}")
    


if __name__ == "__main__":
    fire.Fire(prepare_template, name="prepare_template")

