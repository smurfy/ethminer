---
layout: default
title: Main
---

**ethminer** is an OpenSource Ethereum GPU miner. It is actively maintained. 

## Features
* OpenCL mining (AMD + Nvidia)
* CUDA mining (Nvidia)
* Stratum and Getwork support with failover
* Windows, Linux and osx support

## Usage

**ethminer** is a command line program. You need to launch it either from a Windows command prompt or Linux console.
For easier handling you also can create Windows batch/cmd files or a Linux Batch script.

Full list of all available commands:

``./ethminer --help`` or ``ethminer.exe --help``

### Sample usages

Nanopool, CUDA, stratum with hashrate reporting on windows

``ethminer.exe -RH -SP 1 -U -S eth-eu1.nanopool.org:9999 -O <YOUR-ACCOUNT>.rig``

Nanopool, OpenCL, getwork on linux

``./ethminer -G -F http://eth-eu1.nanopool.org:8888/<YOUR-ACCOUNT>.rig``

Ethermine, Mixed GPUs, stratum with hashrate reporting on windows

``ethminer.exe -RH -X -S eu2.ethermine.org:4444 -O <YOUR-ACCOUNT>.rig``

Ethermine, CUDA, enabled api in read-only, stratum with hashrate reporting on windows

``ethminer.exe --api-port -3333 -RH -U -S eu2.ethermine.org:4444 -O <YOUR-ACCOUNT>.rig``

## Basic JSON-RPC API

Since version 0.12 **ethminer** supports basic api support for stats and if not in read-only mode to restart the miner remotely.
You need to start **ethminer** with ``--api-port <portnum>`` to enable the api. 

Use a positive number like ``--api-port 3333`` to enable read-write mode or a negative number like ``--api-port -3333`` in read-only mode.
Both samples enable the api on port ``3333``.

The api itself is claymore miner compatible. So you should be able to use any monitoring tool supporting that protocol.

For example:
* Ethman shipped with Claymore on Windows
* [Ethmon](https://github.com/osnwt/ethmon) (needs a small patch)

You also can send the raw messages to the port to get a json response:

Stats: ``{"id":0,"jsonrpc":"2.0","method":"miner_getstat1"}``

Restart miner: ``{"id":0,"jsonrpc":"2.0","method":"miner_restart"}``