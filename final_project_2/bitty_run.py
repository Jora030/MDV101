
import os
import subprocess
import shutil
import sys

MODULES = {
    "bitty_core": {
        "src": "rtl/bitty_core.v",
        "tb": "rtl/bitty_core_tb.cpp"
    }
}

def compile_and_run(module):
    print(f"\n🔧 Compiling {module}...")

    src = MODULES[module]["src"]
    tb = MODULES[module]["tb"]
    build_dir = f"build/{module}"
    os.makedirs(build_dir, exist_ok=True)

    shutil.copy(src, os.path.join(build_dir, os.path.basename(src)))
    shutil.copy(tb, os.path.join(build_dir, os.path.basename(tb)))

    # add alu.v, controller.v, reg16.v
    extra_files = ["rtl/alu.v", "rtl/controller.v", "rtl/reg16.v"]
    for f in extra_files:
        shutil.copy(f, os.path.join(build_dir, os.path.basename(f)))

    subprocess.run([
        "verilator",
        "--cc", os.path.basename(src),
        "--exe", os.path.basename(tb),
        "--build",
        "-o", "sim.out",
        "--Mdir", "."
    ], cwd=build_dir, check=True)

    print(f"🚀 Running {module} simulation...")
    with subprocess.Popen(
        ["./sim.out"],
        cwd=build_dir,
        stdout=sys.stdout,
        stderr=sys.stderr
    ) as proc:
        proc.wait()

if __name__ == "__main__":
    for mod in MODULES:
        compile_and_run(mod)
