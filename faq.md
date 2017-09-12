---
layout: default
title: F.A.Q
---

## F.A.Q

* Why is my hashrate with Nvidia cards on Windows 10 so low?

   The new WDDM 2.x driver on Windows 10 uses a different way of addressing the GPU. This is good for a lot of things, but not for ETH mining.
   For Kepler GPUs: I actually don't know. Please let me know what works best for good old Kepler.
   For Maxwell 1 GPUs: Unfortunately the issue is a bit more serious on the GTX750Ti, already causing suboptimal performance on Win7 and Linux. Apparently about 4MH/s can still be reached on Linux, which, depending on ETH price, could still be profitable, considering the relatively low power draw.
   For Maxwell 2 GPUs: There is a way of mining ETH at Win7/8/Linux speeds on Win10, by downgrading the GPU driver to a Win7 one (350.12 recommended) and using a build that was created using CUDA 6.5.
   For Pascal GPUs: You have to use the latest WDDM 2.1 compatible drivers in combination with Windows 10 Anniversary edition in order to get the full potential of your Pascal GPU.

* Why is a GTX 1080 slower than a GTX 1070?

   Because of the GDDR5X memory, which can't be fully utilized for ETH mining (yet).

* Are AMD cards also affected by slowdowns with increasing DAG size?

   Only GCN 1.0 GPUs (78x0, 79x0, 270, 280), but in a different way. You'll see that on each new epoch (30K blocks), the hashrate will go down a little bit.

* Can I still mine ETH with my 2GB GPU?

   No. Your VRAM must be above the DAG size (At the time of writing about 2.15 GB.)

* What are the optimal launch parameters?

   The default parameters are fine in most scenario's (CUDA). For OpenCL it varies a bit more. Just play around with the numbers and use powers of 2. GPU's like powers of 2.
   
* What does the ```--cuda-parallel-hash``` flag do?

   @davilizh made improvements to the CUDA kernel hashing process and added this flag to allow changing the number of tasks it runs in parallel. These improvements were optimised for GTX 1060 GPUs which saw a large increase in hashrate, GTX 1070 and GTX 1080/Ti GPUs saw some, but less, improvement. The default value is 4 (which does not need to be set with the flag) and in most cases this will provide the best performance.

* What is ethminer's relationship with [Genoil's fork]?

  [Genoil's fork] was the original source of this version, but as Genoil is no longer consistently maintaining that fork it became almost impossible for developers to get new code merged there. In the interests of progressing development without waiting for reviews this fork should be considered the active one and Genoil's as legacy code.

* Can I CPU Mine?

  No, use geth, the go program made for ethereum by the ethereum-project.
  But please be aware, that CPU mining is not really effective anymore.


[Genoil's fork]: https://github.com/Genoil/cpp-ethereum

