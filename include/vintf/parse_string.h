/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_VINTF_PARSE_STRING_H
#define ANDROID_VINTF_PARSE_STRING_H

#include <iostream>
#include <sstream>
#include <string>

#include "CompatibilityMatrix.h"
#include "RuntimeInfo.h"
#include "HalManifest.h"

namespace android {
namespace vintf {

std::ostream &operator<<(std::ostream &os, HalFormat hf);
std::ostream &operator<<(std::ostream &os, Transport tr);
std::ostream &operator<<(std::ostream &os, Arch ar);
std::ostream &operator<<(std::ostream &os, KernelConfigType il);
std::ostream &operator<<(std::ostream &os, Tristate tr);
std::ostream &operator<<(std::ostream &os, SchemaType ksv);
std::ostream &operator<<(std::ostream &os, const ManifestHal &hal);
std::ostream &operator<<(std::ostream &os, const Version &ver);
std::ostream &operator<<(std::ostream &os, const VersionRange &vr);
std::ostream &operator<<(std::ostream &os, const VndkVersionRange &vr);
std::ostream &operator<<(std::ostream &os, const KernelVersion &ver);
std::ostream &operator<<(std::ostream &os, const TransportArch &ta);
std::ostream &operator<<(std::ostream &os, const ManifestHal &hal);
std::ostream &operator<<(std::ostream &os, const MatrixHal &req);
std::ostream &operator<<(std::ostream &os, const KernelConfigTypedValue &kcv);
std::ostream &operator<<(std::ostream &os, const SepolicyVersion &sv);

template <typename T>
std::string to_string(const T &obj) {
    std::ostringstream oss;
    oss << obj;
    return oss.str();
}

bool parse(const std::string &s, HalFormat *hf);
bool parse(const std::string &s, Transport *tr);
bool parse(const std::string &s, Arch *ar);
bool parse(const std::string &s, KernelConfigType *il);
bool parse(const std::string &s, KernelConfigKey *key);
bool parse(const std::string &s, Tristate *tr);
bool parse(const std::string &s, SchemaType *ver);
bool parse(const std::string &s, KernelSepolicyVersion *ksv);
bool parse(const std::string &s, Version *ver);
bool parse(const std::string &s, VersionRange *vr);
bool parse(const std::string &s, VndkVersionRange *vr);
bool parse(const std::string &s, KernelVersion *ver);
// if return true, ta->isValid() must be true.
bool parse(const std::string &s, TransportArch *ta);
// if return true, hal->isValid() must be true.
bool parse(const std::string &s, ManifestHal *hal);
bool parse(const std::string &s, MatrixHal *req);
bool parse(const std::string &s, SepolicyVersion *sv);

bool parseKernelConfigInt(const std::string &s, int64_t *i);
bool parseKernelConfigInt(const std::string &s, uint64_t *i);
bool parseRange(const std::string &s, KernelConfigRangeValue *range);

// Parse the KernelConfigValue in s, assuming type kctv->type, and store it in
// kctv->value.
bool parseKernelConfigValue(const std::string &s, KernelConfigTypedValue *kctv);

// A string that describes the whole object, with versions of all
// its components. For debugging and testing purposes only. This is not
// the XML string.
std::string dump(const HalManifest &vm);

std::string dump(const RuntimeInfo &ki);

} // namespace vintf
} // namespace android

#endif // ANDROID_VINTF_PARSE_STRING_H
