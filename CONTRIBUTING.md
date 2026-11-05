# Contributing to Siro

Thanks for helping improve Siro. Small, reviewable changes are easiest to check and merge.

## Before opening a pull request

- For firmware changes, state the ESP32 board and libraries used. Describe the behavior you changed and how you checked it.
- For motion changes, include the affected joint labels, starting posture, and a short low speed test procedure. Avoid asking others to test an unbounded movement on a physical robot.
- For STL changes, include the source CAD file when available, the exported STL, units, print orientation, and any required supports or hardware.
- Keep new binary files limited to the models needed for the change. Do not include slicer caches, machine profiles, or unrelated exports.
- Preserve upstream attribution and the included Apache 2.0 license when adapting Sesame Robot material.

## Reporting a bug

Include the firmware version, board, power arrangement, steps to reproduce, expected behavior, and what happened. Remove Wi-Fi passwords and other private credentials from logs and screenshots.

## Pull requests

Explain the problem, summarize the change, and list the checks performed. If the change needs hardware that is not available to you, say so clearly so reviewers can distinguish code review from physical validation.
