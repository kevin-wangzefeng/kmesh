/*
 * Copyright 2023 The Kmesh Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* When the two ends use loopback addresses for communication, there is a 
 * low probability that link conflicts occur. The namespace cookie 
 * corresponding to each container is added to the hash key to avoid 
 * loopback address link conflicts. Obtains the namespace cookie of the
 * current container based on the bpf_get_netns_cookie auxiliary function.
*/
#define MDA_LOOPBACK_ADDR	1

/* supports NAT acceleration. That is, acceleration can also be performed 
 * when iptables is used to forward traffic between service containers 
 * and sidecar containers. The bpf_sk_original_addr auxiliary function is 
 * used to obtain the original destination address.
*/
#define MDA_NAT_ACCEL		1

/* supports acceleration function filtering based on GID and UID. 
 * That is, the GID or UID corresponding to the process to be accelerated 
 * is configured in the configuration file. The bpf_get_sockops_uid_gid 
 * auxiliary function is used to obtain the GID and UID of the current 
 * process.
*/
#define MDA_GID_UID_FILTER	1

/* In the kernel network protocol stack, the port is stored in u16, 
 * but in the bpf network module, the port is stored in u32. Therefore, 
 * after the endian conversion, the 16-bit port needs to be obtained from 
 * the 32-bit data structure. You need to find the position of the valid 
 * 16 bits. Generally, after the port is extended from 16 bits to 32 bits, 
 * the port is in the upper 16 bits after the endian conversion. 
 * Therefore, you need to offset the port before using the u16 RX port.
 * In some specific kernels, the port stored in sockops is in the lower 
 * 16 bits and does not need to be offset.
 */
#define MDA_PORT_OFFSET		1
