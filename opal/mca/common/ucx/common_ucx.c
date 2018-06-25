/*
 * Copyright (C) Mellanox Technologies Ltd. 2018. ALL RIGHTS RESERVED.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#include "opal_config.h"

#include "common_ucx.h"
#include "opal/mca/base/mca_base_var.h"

/***********************************************************************/

int opal_common_ucx_progress_iterations = 100;

OPAL_DECLSPEC void opal_common_ucx_mca_register(void)
{
    static int registered = 0;

    if (registered) {
        /* process once */
        return;
    }

    registered = 1;
    mca_base_var_register("opal", "opal_common", "ucx", "progress_iterations",
            "Set number of calls of internal UCX progress calls per opal_progress call",
            MCA_BASE_VAR_TYPE_INT, NULL, 0, MCA_BASE_VAR_FLAG_SETTABLE,
            OPAL_INFO_LVL_9, MCA_BASE_VAR_SCOPE_LOCAL,
            &opal_common_ucx_progress_iterations);
}

void opal_common_ucx_empty_complete_cb(void *request, ucs_status_t status)
{
}
