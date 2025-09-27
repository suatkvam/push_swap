#!/usr/bin/env bash
set -euo pipefail

PS=./push_swap
CK=./checker_linux

run_case() {
  local args="$1"
  local name="$2"
  local ops
  # Split args string into an array (words become separate CLI args)
  # shellcheck disable=SC2206
  local arr=( $args )
  ops=$("$PS" "${arr[@]}" | wc -l)
  if ! "$PS" "${arr[@]}" | "$CK" "${arr[@]}" >/dev/null; then
    echo "[FAIL] $name: checker failed"
    exit 1
  fi
  echo "[OK]   $name: ops=$ops"
}

run_case_single_arg() {
  local argstr="$1"
  local name="$2"
  local ops
  ops=$("$PS" "$argstr" | wc -l)
  if ! "$PS" "$argstr" | "$CK" "$argstr" >/dev/null; then
    echo "[FAIL] $name: checker failed"
    exit 1
  fi
  echo "[OK]   $name: ops=$ops"
}

# Deterministic tiny cases
run_case "3 2" "2 nums (3 2)"
run_case "2 1 3" "3 nums easy"
run_case "3 2 1" "3 nums worst"
run_case "5 4 3 2 1" "5 descending"

# Single-argument input parsing
run_case_single_arg "4 3 2 1" "single-arg 4 descending"

# Random small/mid cases (keep counts modest)
rand_args() {
  local n=$1
  seq 1 "$n" | shuf | tr '\n' ' '
}

for n in 10 20 21 50; do
  ARGS=$(rand_args "$n")
  run_case "$ARGS" "random $n"
done

# Descending sequences to exercise worst-ish cases for current algs
for n in 21 50; do
  ARGS=$(seq "$n" -1 1 | tr '\n' ' ')
  run_case "$ARGS" "$n descending"
done

echo "All smoke tests passed."