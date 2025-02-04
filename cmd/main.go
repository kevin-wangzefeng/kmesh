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

 * Author: LemmyHuang
 * Create: 2021-10-09
 */

package main

import (
	"fmt"

	"oncn.io/mesh/cmd/command"
)

func main() {
	if err := command.StartClient(); err != nil {
		fmt.Println(err)
	}
	defer func() {
		if err := command.StopClient(); err != nil {
			fmt.Printf("failed when stop client, err:%s", err)
		}
	}()
}
