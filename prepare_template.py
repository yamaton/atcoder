import pathlib
import string
import sys
import shutil
import fire

TO_EXT = {
    "c++": ".cc",
    "cpp": ".cc",
    ".cpp": ".cc",
    "rust": ".rs",
    "python": ".py",
    "f#": ".fsx",
    "fsharp": ".fsx",
    "fs": ".fsx",
}

def get_ext(lang):
    if lang in TO_EXT:
        lang = TO_EXT[lang]
    ext = lang if lang.startswith(".") else "." + lang
    return ext


def prepare_template(s, count=4, lang=".rs"):
    p = pathlib.Path(s)
    p.mkdir(exist_ok=True)
    ext = get_ext(lang)
    src = p.parent / "templates" / ("template" + ext)
    assert src.exists(), f"template file not found! {src}"

    print(f"Created {p}")
    problems = string.ascii_lowercase[:count]
    for c in problems:
        dst = p / (s + "_" + c + ext)
        if dst.exists():
            print(f"{dst} already exists. skipping...")
        else:
            shutil.copy2(src, dst)
            print(f"Copied from {src} to {dst}")
    


if __name__ == "__main__":
    fire.Fire(prepare_template, name="prepare_template")

