#!/bin/bash
read -p "Enter height " input

right_angle_triangle() {
  local rows=$1
  for ((i=1; i<=rows; i++)); do
    for ((j=1; j<=i; j++)); do
      printf "* "
    done
    echo ""
  done
}
right_angle_triangle input

pyramid() {
  local rows=$1
  local spaces
  local stars

  for ((i=1; i<=rows; i++)); do
    spaces=$((rows - i))
    stars=$((2 * i - 1))

    for ((j=1; j<=spaces; j++)); do
      printf " "
    done

    for ((j=1; j<=stars; j++)); do
      printf "*"
    done
    echo ""
  done
}
pyramid input

diamond() {
  local rows=$1
  local spaces
  local stars
  local i
  local j

  # Upper half of diamond
  for ((i=1; i<=rows; i++)); do
    spaces=$((rows - i))
    stars=$((2 * i - 1))

    for ((j=1; j<=spaces; j++)); do
      printf " "
    done

    for ((j=1; j<=stars; j++)); do
      printf "*"
    done
    echo ""
  done

  # Lower half of diamond
  for ((i=rows-1; i>=1; i--)); do
    spaces=$((rows - i))
    stars=$((2 * i - 1))

    for ((j=1; j<=spaces; j++)); do
      printf " "
    done

    for ((j=1; j<=stars; j++)); do
      printf "*"
    done
    echo ""
  done
}
diamond input
