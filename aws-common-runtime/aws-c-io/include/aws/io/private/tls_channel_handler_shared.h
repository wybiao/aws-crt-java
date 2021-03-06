#ifndef AWS_IO_TLS_CHANNEL_HANDLER_SHARED_H
#define AWS_IO_TLS_CHANNEL_HANDLER_SHARED_H
/*
 * Copyright 2010-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include <aws/io/io.h>

#include <aws/io/channel.h>
#include <aws/io/statistics.h>

struct aws_tls_connection_options;

struct aws_tls_channel_handler_shared {
    uint32_t tls_timeout_ms;
    struct aws_channel_handler *handler;
    struct aws_channel_task timeout_task;
    struct aws_crt_statistics_tls stats;
};

AWS_EXTERN_C_BEGIN

AWS_IO_API void aws_tls_channel_handler_shared_init(
    struct aws_tls_channel_handler_shared *tls_handler_shared,
    struct aws_channel_handler *handler,
    struct aws_tls_connection_options *options);

AWS_IO_API void aws_tls_channel_handler_shared_clean_up(struct aws_tls_channel_handler_shared *tls_handler_shared);

AWS_IO_API void aws_on_drive_tls_negotiation(struct aws_tls_channel_handler_shared *tls_handler_shared);

AWS_IO_API void aws_on_tls_negotiation_completed(
    struct aws_tls_channel_handler_shared *tls_handler_shared,
    int error_code);

AWS_EXTERN_C_END

#endif /* AWS_IO_TLS_CHANNEL_HANDLER_SHARED_H */
