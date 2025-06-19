#!/bin/bash
set -euo pipefail

if [[ "$#" -lt 2 || "$1" != "--ort-path" ]]; then
    echo "usage: $0 --ort-path <path_to_onnxruntime>" >&2
    exit 1
fi

ORT_ROOT="$2"
shift 2

if [[ ! -d "$ORT_ROOT" || ! -d "$ORT_ROOT/lib" || ! -d "$ORT_ROOT/include" ]]; then
    echo "invalid onnxruntime library path: $ORT_ROOT" >&2
    exit 1
fi

arch=x64
build_dir=build-linux/$arch
rm -rf $build_dir
mkdir -p $build_dir
cd $build_dir

# Step 1: Build the demo
cmake ../../ -DORT_ROOT="$ORT_ROOT"
cmake --build . --config Release

# Step 2: Run the demo
ln -s ../../onnx_model/
./ten_vad_demo ../../../examples/s0724-s0730.wav out.txt

cd ../../
