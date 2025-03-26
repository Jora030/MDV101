
import os
import subprocess
import shutil
import sys

MODULES = {
    "reg16": {
        "src": "rtl/reg16.v",
        "tb": "test/reg16/reg16_tb.cpp"
    },
    "mux": {
        "src": "rtl/mux.v",
        "tb": "test/mux/mux_tb.cpp"
    },
    "alu": {
        "src": "rtl/alu.v",
        "tb": "test/alu/alu_tb.cpp"
    },
    "shifter": {
        "src": "rtl/shifter.v",
        "tb": "test/shifter/shifter_tb.cpp"
    },
    "comparator": {
        "src": "rtl/comparator.v",
        "tb": "test/comparator/comparator_tb.cpp"
    },
    "controller": {
        "src": "rtl/controller.v",
        "tb": "test/controller/controller_tb.cpp"
    },
    "bitty_core": {
        "src": "rtl/bitty_core.v",
        "tb": "test/bitty_core/bitty_core_tb.cpp"
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
